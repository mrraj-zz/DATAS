class Number
  
  def self.to_words(number)
    Number.new.to_s(number)
  end
  
  def self.commify(number)
    (s=number.to_s;x=s.length;s).rjust(x+(3-(x%3))).gsub(/(\d)(?=\d{3}+(\.\d*)?$)/,'\1,')
  end
    
  def initialize
    @unit = %w[zero one two three four five six seven eight nine]
    @teen = %w[ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen]
    @tens = %w[zero ten twenty thirty fourty fifty sixty seventy eighty ninety]
    @qtys = %w[hundred thousand million billion trillion quadrillion quintillion]
    @zero = ["zero"]
    @hundred = "hundred"
    @sepr = "and"
  end
    
  def to_s(number)
    out = quantify(number).flatten
    for x in 0 .. out.length - 1
      out[x] = nil if out[x] == @sepr && out[x+1] == @sepr
    end
    out.compact!
    out = @zero if out.length == 1 && out[0] == @sepr
    out.pop while out.last == @sepr
    out.shift while out.first == @sepr    
    out.join(' ').gsub(/ ,/,',')
  end
        
  private 
  
  def padded_groups(v)
    out = []
    padded = (s=v.to_s;x=s.length;s).rjust(x+(3-(x%3))).gsub(//,'0')
    padded.scan(/.{3}/)
  end
  
  def wordify(v)
    out = []
    zero = '0'[0]
    h, t, u = v[0] - zero, v[1] - zero, v[2] - zero
    if h != 0
      out << @unit[h]
      out << @hundred
    end
    out << @sepr if h != 0 && (t != 0 || u != 0)
    out << @sepr if h == 0 && t == 0 && u != 0
    if t == 1
      out << @teen[u]
    else
      out << @tens[t] if t != 0
      out << @unit[u] if u != 0
    end
    return out
  end
  
  def quantify(v)
    v = padded_groups(v).reverse
    pos = v.length - 1
    out = []
    while pos >= 0
      word = wordify(v[pos])
      if word[0] != nil
        out << word
        out << @qtys[pos] if pos != 0                
      else
        out << @sepr
      end
      pos -= 1
    end
    return out
  end

end
 for number in [
     0, 
     1, 
     3, 
     11, 
     100,
     1000, 
     1001, 
     1100, 
     1101, 
     1_000_001, 
     8_000_000_000, 
     8_000_000_001, 
     4_567_890_923, 
     6_804_567_890_903, 
     5_006_804_567_890_903
   ]
   print "#{Number.commify(number)}: #{Number.to_words(number)}\n"
 end
