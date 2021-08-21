#/usr/bin/ruby

def f (n)
  if n >= 2
    return f(n - 1) + f(n - 2)
  else
    return n
  end
end

puts "Enter number n; n is an integer and greater than or equal to zero."
n = gets.chomp
puts "Your input: #{n}"

unless n =~ /^[0-9]+$/
  puts "You must enter an integer."
  return
end

n = n.to_i
answer = f(n)
puts "Answer: #{answer}"
