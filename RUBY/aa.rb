class Fixnum
	def english_word
		@h = { 0=>"zero", 1=>"One", 2=>"Two", 3=>"Three",4=>"Four", 5=>"Five",6=>"six", 7=>"seven", 8=>"Eight",9=>"Nine",10=>"Ten",11=>"Eleven",12=>"Twelve",13=>"Thirteen",14=>"Fourteen",15=>"Fifteen",16=>"Sixteen",17=>"Seventeen",18=>"Eighteen",19=>"Nineteen",20=>"Twenty",30=>"Thirty",40=>"Fourty",50=>"Fifty",60=>"Sixty",70=>"Seventy",80=>"Eighty",90=>"Ninty" }
		@i = 0
		@array = []
  	@result = ""
		result = ""
  	if self > 99
			str_num = self.to_s #@num.to_s
			str_num_len = str_num.length
			str_full_num = str_num.insert(0,"0"*(11-str_num_len))
			str_full_num = str_num.insert(8,"0")
			str_full_num.scan(/../) { |x|  @array<<x }
			6.times do
				@i+= 1
					val = self.def_calc
					if val						
						result = val 
					end
			end
			result
		else
    	if self > 9
        result =  (self.proc_double_dig( ( self/10 )*10 ) )+( self.proc_single_dig( self%10 ) )
     	else
      	if self > 0
       		result = self.proc_single_dig( self )
       	else
        	return "AMOUNT NOT KNOWN or NILL"
       	end
     	end
			result
		end
	end

  def def_calc
    case @i
      when 0
        str = self.proc_unit( @array[@i] )
        if ( str.scan(/\w+/) ).length != 0
        	then str = str+ "hundred & "
        	@result = @result + str
        end
        @result.sub(/..$/,"")
      when 1
        str = self.proc_unit( @array[@i] )
        if ( str.scan(/\w+/) ).length != 0
        	then str = str+ " Crore, "
        	@result = @result + str
        end
        @result.sub(/..$/,"")
      when 2
        str = self.proc_unit( @array[@i] )
        if ( str.scan(/\w+/) ).length != 0
        	then str = str+ " Lakh, "
       		@result = @result + str
        end
        @result.sub(/..$/,"")
      when 3
        str = self.proc_unit( @array[@i] )
        if ( str.scan(/\w+/) ).length != 0
        	then str = str+ " Thousand, "
        	@result = @result + str
        end
        @result.sub(/..$/,"")
      when 4
        str = self.proc_unit( @array[@i] )
        if ( str.scan(/\w+/) ).length != 0
        	then str = str+ " Hundred, "
        	@result = @result + str
        end
        @result.sub(/..$/,"")
      when 5
        str = self.proc_unit(@array[@i] )
        if ( str.scan(/\w+/) ).length != 0
        	then str = str+ ". "
        	@result = @result + str
        end
        @result.sub(/..$/,"")
    else
   	end
  end

  def proc_unit( x )
  	if x.to_i > 0
    	if x.to_i <= 10
        return self.proc_single_dig( x.to_i )
      else
        if x.to_i <= 20
        	return self.proc_double_dig( x.to_i )
        else
        	return ( self.proc_double_dig( ( x.to_i/10 )*10 ) )+( self.proc_single_dig( x.to_i%10 ) )
        end
     	end
    end
  	return ""
	end

  def proc_double_dig( z )
    if z == 0
      return ""
    else
      return @h[z]
    end
	end

  def proc_single_dig( y )
    if y == 0
      return ""
    else
      return @h[y]
    end
  end
protected :def_calc, :proc_unit, :proc_double_dig,:proc_single_dig

end

# This will work only for Fixnum (below 999999999)
