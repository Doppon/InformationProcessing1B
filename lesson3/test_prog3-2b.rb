array = []

File.open("2018_population.csv") do |f|
  f.each_line do |line|
    locate, num = line.chomp.split(" ")
    array << num.to_i
  end
end

puts array.sum / array.length
