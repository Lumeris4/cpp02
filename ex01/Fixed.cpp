/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:42:00 by lelanglo          #+#    #+#             */
/*   Updated: 2025/02/19 12:04:22 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_stock_bits = 8;

Fixed::Fixed(): _stock(0) {std::cout << "Default Constructor called\n";}

Fixed::~Fixed() {std::cout << "Destructor called\n";}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called\n";
	this->_stock = (number << this->_stock_bits);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called\n";
	this->_stock = roundf(number * (1 << this->_stock_bits));	
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
	return;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->_stock = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	return this->_stock;
}

void Fixed::setRawBits(int const raw) {this->_stock = raw;}

int Fixed::toInt() const
{
	return (this->_stock >> this->_stock_bits);
}

float Fixed::toFloat() const
{
	return((float)this->_stock / (float)(1 << this->_stock_bits));
}

std::ostream	&operator<<(std::ostream &output, const Fixed &other)
{
	output << other.toFloat();
	return (output);
}