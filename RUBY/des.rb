class Namee
  def initialize(name, file)
      @name = name
      @file = file
      ObjectSpace.define_finalizer( self, self.class.finalize(name) )	
	p 'ggggg'
  end
  def self.finalize(name)
	proc { IL.DeleteImages(1, [name]) }
	p 'deleted:'+name
  end
end

nn = Namee.new
