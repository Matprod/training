/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:17:02 by fatkeski          #+#    #+#             */
/*   Updated: 2025/10/02 13:21:27 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"


class searchable_array_bag : public array_bag , public searchable_bag{
	private:
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag &source);
		searchable_array_bag& operator=(const searchable_array_bag& source);
		bool has(int) const;
		~searchable_array_bag();
};














/* class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag& source);
		searchable_array_bag& operator=(const searchable_array_bag& source);
		bool has(int) const;
		~searchable_array_bag();
};
*/
