
module AttrModule
	def attr_value
		'attr_value'
	end
end

class Attr
	def attr_name
		'Attr_Name'
	end
end

Attr.extend(AttrModule)
