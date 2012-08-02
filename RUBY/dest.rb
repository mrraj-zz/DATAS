class MyClass
    def initialize
       p  ObjectSpace.define_finalizer(self, self.class.method(:finalize).to_proc)
	p 'gggggggggggggggg'
    end
	def calll
		p 'sss'
		p self
	end
    def MyClass.finalize(id)
        puts "Object #{id} dying at #{Time.new}"
    end
end

# test code
3.times {
    MyClass.new.calll
}

