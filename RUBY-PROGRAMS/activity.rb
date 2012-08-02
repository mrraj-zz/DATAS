class Activity
	def name
		"Mohanraj"
	end
end

class CookActivity < Activity
	def cook_name
		"Cook"
	end
end

cook = CookActivity.new
p cook

act = Activity.new
p act
