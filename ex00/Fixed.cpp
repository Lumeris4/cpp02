/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:14:26 by lelanglo          #+#    #+#             */
/*   Updated: 2025/02/17 13:03:33 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_stock_bits = 8;

Fixed::Fixed(): _stock(0) {};

Fixed::~Fixed() {};

Fixed::Fixed(const Fixed &other)
{
	*this = other;
	return;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_stock = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {return this->_stock;}

void Fixed::setRawBits(int const raw) {this->_stock = raw;}