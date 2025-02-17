/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:56:09 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/17 12:56:09 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::min()

#define CHAR_MAX std::numeric_limits<char>::max()
#define CHAR_MIN std::numeric_limits<char>::min()



class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        static void convert(const char *input);

};

#endif
