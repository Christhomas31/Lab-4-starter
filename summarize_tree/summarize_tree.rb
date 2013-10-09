#!/usr/bin/ruby

require 'find'
num_dir = 0
num_file = 0 
Find.find(ARGV[0]) do |path|
  if FileTest.directory?(path)
      num_dir += 1
  end
  if FileTest.file?(path)
      num_file += 1
  end
end

puts "Processed all the files from #{ARGV[0]}."
puts "There were #{num_dir} directories."
puts "there were #{num_file} files."

 
