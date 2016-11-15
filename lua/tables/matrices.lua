#!/bin/lua

mt = {} -- create the matrix
for i=1, 10 do
	mt[i] = {}
	for j = 1, 10 do
		mt[i][j] = i * j
	end
end

for k, v in ipairs(mt) do
	local i = 1
	while v[i] ~= nil do
		print(tostring(v[i]))
		i = i + 1
	end
end


