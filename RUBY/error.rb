class MyError
	raise MException.new('error')
	def value
		i/0
	end
	def self.rescue_from(e)
		p e
		p 'bbbbbbbbbbbbbb'
	end
end

class MException < Exception
	def initialize( error )
		super( error )
	end
end

m = MyError.new
m.value
M
