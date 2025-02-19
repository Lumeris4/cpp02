/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:42:04 by lelanglo          #+#    #+#             */
/*   Updated: 2025/02/19 12:07:38 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{

	private:
	
	int _stock;
	static const int _stock_bits;
	
	public:
	
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	bool	operator>(Fixed other)const;
	bool	operator<(Fixed other)const;
	bool	operator>=(Fixed other)const;
	bool	operator<=(Fixed other)const;
	bool	operator==(Fixed other)const;
	bool	operator!=(Fixed other)const;
	float	operator+(Fixed other)const;
	float	operator-(Fixed other)const;
	float	operator*(Fixed other)const;
	float	operator/(Fixed other)const;
	Fixed	operator++();
	Fixed	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);
	
	float toFloat(void) const;
	int toInt(void) const;
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	static	Fixed &min(Fixed &first, Fixed &second);
	static	const Fixed &min(Fixed const &first, Fixed const &second);
	static	Fixed &max(Fixed &first, Fixed &second);
	static	const Fixed &max(Fixed const &first, const Fixed &second);
};

std::ostream	&operator<<(std::ostream &output, const Fixed &other);