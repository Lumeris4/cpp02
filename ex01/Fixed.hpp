/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:42:04 by lelanglo          #+#    #+#             */
/*   Updated: 2025/02/17 14:16:25 by lelanglo         ###   ########.fr       */
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
	
	float toFloat(void) const;
	int toInt(void) const;
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &output, const Fixed &fixed);