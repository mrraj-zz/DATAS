class Fixnum
def english_word
@h = {0=>"zero", 1=>"One", 2=>"Two", 3=>"Three",
4=>"Four", 5=>"Five",6=>"six", 7=>"seven", 8=>"Eight",
9=>"Nine",10=>"Ten",11=>"Eleven",12=>"Twelve",
13=>"Thirteen",14=>"Fourteen",15=>"Fifteen",
16=>"Sixteen",17=>"Seventeen",18=>"Eighteen",
19=>"Nineteen",20=>"Twenty",30=>"Thirty",
40=>"Fourty",50=>"Fifty",60=>"Sixty",70=>"Seventy",
80=>"Eighty",90=>"Ninty"}
@i=0
@array=[]
@result="a"
if self > 99
str_num=self.to_s #...@num.to_s
str_num_len=str_num.length
str_full_num=str_num.insert(0,"0"*(11-str_num_len))
str_full_num=str_num.insert(8,"0")
str_full_num.scan(/../) { |x| @array<<x }
6.times do
self.def_calc
@i+=1
end
else
if self > 9
puts
(self.proc_double_dig((self/10)*10))+
(self.proc_single_dig(self%10))
else
if self > 0
puts self.proc_single_dig(self)
else
return "AMOUNT NOT KNOWN or NILL"
end
end
end
end

def def_calc
case @i
when 0
str=self.proc_unit([@arr...@i])
if (str.scan(/\w+/)).length!=0
then str=str+ "hundred & "
@resu...@result+str
end
when 1
str=self.proc_unit([@arr...@i])
if (str.scan(/\w+/)).length!=0
then str=str+ " Crore, "
@resu...@result+str
end
when 2
str=self.proc_unit([@arr...@i])
if (str.scan(/\w+/)).length!=0
then str=str+ " Lakh, "
@resu...@result+str
end
when 3
str=self.proc_unit([@arr...@i])
if (str.scan(/\w+/)).length!=0
then str=str+ " Thousand, "
@resu...@result+str
end
when 4
str=self.proc_unit([@arr...@i])
if (str.scan(/\w+/)).length!=0
then str=str+ " Hundred, "
@resu...@result+str
end
when 5
str=self.proc_unit([@arr...@i])
if (str.scan(/\w+/)).length!=0
then str=str+ ". "
@resu...@result+str
end
print @result.sub(/..$/,"")
else
end
end

def proc_unit(x)
if x.to_i>0
if x.to_i<=10
return self.proc_single_dig(x.to_i)
else
if x.to_i<=20
return self.proc_double_dig(x.to_i)
else
return
(self.proc_double_dig((x.to_i/10)*10))+
(self.proc_single_dig(x.to_i%10))
end
end
end
return ""
end

def proc_double_dig(z)
if z==0
return ""
else
return @h[z]
end
end

def proc_single_dig(y)
if y==0
return ""
else
return @h[y]
end
end
protected :def_calc, :proc_unit, :proc_double_dig,:proc_single_dig

end

puts 453645445.english_word
