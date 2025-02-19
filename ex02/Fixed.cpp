/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:42:00 by lelanglo          #+#    #+#             */
/*   Updated: 2025/02/19 12:11:42 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_stock_bits = 8;

Fixed::Fixed(): _stock(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int number)
{
	this->_stock = (number << this->_stock_bits);
}

Fixed::Fixed(const float number)
{
	this->_stock = roundf(number * (1 << this->_stock_bits));	
}

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

bool	Fixed::operator>(Fixed other)const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(Fixed other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(Fixed other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(Fixed other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(Fixed other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(Fixed other) const
{
	return (this->toFloat() != other.toFloat());
}

float	Fixed::operator+(Fixed other) const
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(Fixed other) const
{
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(Fixed other) const
{
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(Fixed other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_stock++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_stock--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;

	++this->_stock;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;

	--this->_stock;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}
