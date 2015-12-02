

stock_prices_yesterday = [0, 7, 5, 8, 11, 9]



min_price = stock_prices_yesterday[0]
min_i = 0
max_price = stock_prices_yesterday[1]
max_i = 1
max_earning = -1


def stocks(sp, mi, mxi):

	if(mxi == len(sp)-1):
		return sp[mxi] - sp[mi]

	if(mxi == mi or mxi >= len(sp)):
		return 0

	return max(sp[mxi] - sp[mi], stocks(sp, mxi, mxi+1))


def stocks_nor(sp):
	max_profit = -1
	min_price = sp[0]
	for i in range(1, len(sp)):
		min_price = min(sp[i], min_price)
		if min_price == sp[i]:
			continue
		potential_profit = sp[i] - min_price

		if potential_profit > max_profit:
			max_profit = potential_profit

	return max_profit

print stocks(stock_prices_yesterday, 0, 1)


print stocks_nor(stock_prices_yesterday)