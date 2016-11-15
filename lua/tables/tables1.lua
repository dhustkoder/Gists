#!/bin/lua

squares = {}
for i = 1, 100 do
	squares[i] = i * i
end

for k, v in ipairs(squares) do
	print(tostring(v))
end





