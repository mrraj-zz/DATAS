class Factorial
	def calculate( value )
		if value == 0
			value
		else
			value*calculate( value - 1 )
		end
	end
end

factorial = Factorial.new
puts factorial.calculate( 3 )

def calculate(v, options = {} )
	if v && options
		p v
	end
end
