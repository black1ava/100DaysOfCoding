arr = [1, 2, 3, 4]
n = arr.length
for i in(0...n)
  next unless i % 2 == 0
  arr[i], arr[i + 1] = arr[i + 1], arr[i]
end

arr.each {|x| print "#{x} "}