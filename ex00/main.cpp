/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:46:03 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/17 18:46:03 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"



int main(int ac, char **av)
{
    // Standard tests:

    // (void)ac;
    // (void)av;

    if (ac != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }else if (av[1][0] == '\0')
    {
        std::cout << "Error: Empty string" << std::endl;
        return 1;
    }
    else {

        ScalarConverter::convert(av[1]);
    }

    // Unit tests:

    // ScalarConverter::convert(std::to_string(INT_MAX + 10).c_str());

    // ScalarConverter::convert("42");
    // ScalarConverter::convert("42.0f");
    // ScalarConverter::convert("-42.0");
    // ScalarConverter::convert("42.0f");
    // ScalarConverter::convert("42.0f");
    // ScalarConverter::convert("A");

    return 0;
}
