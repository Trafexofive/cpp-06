/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:51:08 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/18 15:51:08 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

static void PrintLineInfo(const std::string &str)
{
    std::cout << "=====================================================" << std::endl;
    std::cout << "== "<< str << std::endl;
    std::cout << "=====================================================" << std::endl;
}

int main()
{

    std::srand(time(NULL));

    Base base;

    Base *ptr = base.generate();
    Base *ptr2 = base.generate();
    Base *ptr3 = base.generate();

    Base &ref = *ptr;
    Base &ref2 = *ptr2;
    Base &ref3 = *ptr3;

    PrintLineInfo("Identify using pointer");

    base.identify(ptr);
    base.identify(ptr2);
    base.identify(ptr3);

    PrintLineInfo("Identify using refrance");

    base.identify(ref);
    base.identify(ref2);
    base.identify(ref3);

    delete ptr;
    delete ptr2;
    delete ptr3;

    return 0;
}
