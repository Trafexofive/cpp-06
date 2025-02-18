/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:42:08 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/18 13:42:08 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <ostream>

// ========================= CANONICAL FORM =============================================

Serializer::Serializer()
{
}

// ========================= INSERTION OVERLOAD =========================================

std::ostream & operator<<(std::ostream & o, Data const & rhs)
{
    o << "x: " << rhs.x << std::endl;
    o << "y: " << rhs.y << std::endl;
    o << "magnitude: " << rhs.magnitude << std::endl;
    return o;
}

std::ostream &operator<<(std::ostream &o, Data *rhs)
{
    o << "x: " << rhs->x << std::endl;
    o << "y: " << rhs->y << std::endl;
    o << "magnitude: " << rhs->magnitude << std::endl;

    return o;
}

// ========================= METHODES ===================================================

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

