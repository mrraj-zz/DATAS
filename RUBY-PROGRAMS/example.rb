=begin
class example
	def display( name, value = nil )
		name + value || name
	end
end

example = example.new
puts example.display( "mohanraj", "soundarapandian" )
=end
