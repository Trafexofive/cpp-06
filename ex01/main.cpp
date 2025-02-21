/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:43:04 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/18 13:43:04 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

static void PrintLine(void)
{
    std::cout << "===================================================================="<< std::endl;
}

static void PrintLine(const std::string & str)
{
    std::cout << "===================================================================="<< std::endl;
    std::cout << str << std::endl;
    std::cout << "===================================================================="<< std::endl;
}


int main (void)
{

    Data data;

    data.name = "Vector";

    data.x = 42.42f;
    data.y = 21.21f;

    data.magnitude = 84.84f;

    Data * ptr = &data;

    std::cout << ptr << std::endl;
    PrintLine();
    std::cout << data << std::endl;

    // ========================================================
    uintptr_t intptr = Serializer::serialize(ptr);

    ptr = Serializer::deserialize(intptr);
    // ========================================================

    std::cout << ptr << std::endl;
    PrintLine();
    std::cout << data << std::endl;

}
