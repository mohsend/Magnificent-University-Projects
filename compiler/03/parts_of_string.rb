#! /usr/bin/env ruby

if (!ARGV[0]) then
	puts "Pass a string as a commandline argument."
	exit()
end

# Objective: get a string and make all parts of the string
str = ARGV[0]
last = str.length - 1
len = str.length
# all possible prefixes
puts "========"
puts "'#{str}' has #{len+1} prefixes."
puts "All the prefixes:"

for i in 0..len
  puts str[0,i] # [start, length]
end

# all possible suffixes
puts "========"
puts "'#{str}' has #{len+1} suffixes."
puts "All the suffixes:"

for i in 0..len
  puts str[i,len-i]
end

# all possible substrings

def number_of_substrings(len)
	if (len == 1) then
		return 2;
	end
	return len + number_of_substrings(len - 1)
end
num = number_of_substrings(len)

puts "========"
puts "'#{str}' has #{num} substrings."
puts "All the substrings:"

for i in 0..last
  for j in 1..(len-i)
    puts str[i,j]
  end
end
# nil string
puts ""

# all possible sunsequences
def number_of_sunsequences(len)
	if (len == 1) then
		return 2;
	end
	return len * number_of_sunsequences(len - 1)
end
num = number_of_sunsequences(len)

puts "========"
puts "'#{str}' has #{num} sunsequences."
puts "All the sunsequences:"
puts "???"
