/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:25:02 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/18 16:25:02 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base() {};

        Base *generate(); // for generate a random derived object.

        void identify(Base *p); // for identify the derived object using pointer.
        void identify(Base &p); // since the pointer is not const, we need to use try catch block to catch the exception.
};


// Sample derived Classes to use dynamic cast on.
class A : public Base
{
    public:
        virtual ~A() {};
};

class B : public Base
{
    public:
        virtual ~B() {};
};

class C : public Base
{
    public:
        virtual ~C() {};
};

#endif
