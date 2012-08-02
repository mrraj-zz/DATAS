
class MattrEx
	attr_accessor :api_key
	api_key = '1234rfgtbhgfddgrr'
end

puts 'Default Value'
mattr = MattrEx.new(:api_key => 'ssssssssssssssssssssssss')
p mattr.api_key
mattr.api_key = '00000000000000000'
p mattr.api_key


