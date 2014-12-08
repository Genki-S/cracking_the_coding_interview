
def my_perm(str)
  letters = str.split('')
  raise unless letters.count == letters.uniq.count
  if letters.count == 1
    return letters
  end

  ans = []
  char = letters.last
  prev = my_perm(str[0...(str.length - 1)])
  prev.each do |el|
    (0..el.length).each do |i|
      ans << el[0...i] + char + el[i...el.length]
    end
  end
  ans
end

raise unless my_perm('abc').sort == ['cab', 'acb', 'abc', 'cba', 'bca', 'bac'].sort
