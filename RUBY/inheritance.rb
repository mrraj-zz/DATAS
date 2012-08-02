class M
	def a
		"mohanraj"
	end
end

class N < M
	def b
		"soundar"
	end
end



n = N.new
p n.a # parent class method
p n.b 