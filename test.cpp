################################################################################
#
# The MIT License (MIT)
#
# Copyright (c) 2017 Michael B. Price
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
################################################################################

#include "lockstep.hpp"

#include <array>
#include <vector>
#include <iostream>

int main()
{
    std::array<int, 3> a {42, 99, -1};
    std::cout << "ARRAY: ";
    for (auto& m : a)
        std::cout << m << ", ";
    std::cout << std::endl;

    std::vector<double> v {2.1, 3.2, 4.3};
    std::cout << "VECTOR: ";
    for (auto& m : v)
        std::cout << m << ", ";
    std::cout << std::endl;

    auto x = lockstep::lockstep(a, v);

    int i = 0;
    for (auto b = x.begin(); i < std::min(a.size(), v.size()); ++b, ++i)
    {
        const auto& [first, second] = *b;
        std::cout << "a[" << i << "]: " << first << "\tv[" << i << "]: " << second << std::endl;
    }

    return 0;
}
