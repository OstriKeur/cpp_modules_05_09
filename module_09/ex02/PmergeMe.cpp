#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}


namespace {
    std::vector<int> generateJacobsthal(size_t n) {
        std::vector<int> jacob;
        jacob.push_back(0); jacob.push_back(1);
        int last = 1, prev = 0;
        while (jacob.back() < (int)n) {
            int next = last + 2 * prev;  //  1 3 etc ... to find the next jacobsthal number
            jacob.push_back(next);
            prev = last; last = next;  // update the previous and last values
        }
        return jacob;
    }

    // binary search to find the position to insert the value
    template <typename T>
    typename T::iterator binarySearch(T& container, int val, typename T::iterator end) {
        typename T::iterator begin = container.begin();
        while (begin != end) {
            typename T::iterator mid = begin;
            std::advance(mid, std::distance(begin, end) / 2);
            if (*mid < val) begin = ++mid;
            else end = mid;
        }
        return begin;
    }

    // print the array
    template <typename T>
    void printArray(const T& container, const std::string& prefix) {
        std::cout << prefix;
        typename T::const_iterator it = container.begin();
        for (size_t i = 0; i < container.size(); ++i, ++it) {
            std::cout << *it << " ";
            if (i > 10) { std::cout << "[...]"; break; }
        }
        std::cout << std::endl;
    }
}

// --- Implementation ---

template <typename T>
void PmergeMe::sortContainer(T& container) {
    size_t n = container.size();
    if (n <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1; 
    if (n % 2 != 0) straggler = container.back(); // impaire number of elements

    typename T::iterator it = container.begin();
    for (size_t i = 0; i < n / 2; ++i) {
        int a = *it++;
        int b = *it++;
        if (a > b) pairs.push_back(std::make_pair(a, b));
        else pairs.push_back(std::make_pair(b, a));
    }

    T mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);  // push bigger number first

    sortContainer(mainChain);

    std::vector<int> pend(pairs.size());
    std::vector<bool> used(pairs.size(), false);
    
    typename T::iterator mIt = mainChain.begin();
    for (size_t i = 0; i < mainChain.size(); ++i, ++mIt) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].first == *mIt) {
                pend[i] = pairs[j].second;
                used[j] = true;
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);
    std::vector<int> jacob = generateJacobsthal(pend.size());
    size_t processed = 1;

    for (size_t k = 1; k < jacob.size(); ++k) {
        int curr = jacob[k], prev = jacob[k-1];
        if (curr >= (int)pend.size()) curr = pend.size() - 1;
        for (int i = curr; i > prev; --i) {
            if (i >= (int)pend.size()) continue;
            typename T::iterator pos = binarySearch(mainChain, pend[i], mainChain.end());
            mainChain.insert(pos, pend[i]);
            processed++;
        }
        if (processed >= pend.size()) break;
    }
    
    while (processed < pend.size()) { processed++; } // Safety fallback

    if (straggler != -1) {
        typename T::iterator pos = binarySearch(mainChain, straggler, mainChain.end());
        mainChain.insert(pos, straggler);
    }
    container = mainChain;
}

void PmergeMe::run(int argc, char** argv) {
    std::vector<int> vec;
    std::list<int> list;

    for (int i = 1; i < argc; ++i) {
        std::string s = argv[i];
        for (size_t j = 0; j < s.length(); ++j) 
            if (!isdigit(s[j])) { std::cerr << "Error" << std::endl; return; }
        long val = std::atol(s.c_str());
        if (val < 0 || val > INT_MAX) { std::cerr << "Error" << std::endl; return; }
        vec.push_back((int)val);
        list.push_back((int)val);
    }
    if (vec.empty()) return;

    printArray(vec, "Before: ");

    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    sortContainer(vec);
    gettimeofday(&end, NULL);
    double vecTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    sortContainer(list);
    gettimeofday(&end, NULL);
    double listTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    printArray(vec, "After:  ");
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list  : " << std::fixed << std::setprecision(5) << listTime << " us" << std::endl;
}
