
# create array
a = [1,2,3,4]

# 增删改查
# add item
push!(a, 5) # inplace
insert!(a, 1, 6)
println(a)

# remove item
pop!(a)
deleteat!(a, 1)
println(a)

# assign, index start from 1
a[1] = 4
println(a)
println(a[1])

# iter
# 1. for each
for i in a
    println(i)
end

# 2. for idx
l = length(a)
for i in 1:l
    println(a[i])
end