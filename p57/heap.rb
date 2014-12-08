class Heap
  def initialize(data = [], &comparator)
    @tree = []
    @comp = comparator
    data.each do |datum|
      self.push(datum)
    end
  end

  def top
    @tree.first
  end

  def pop
    return nil if @tree.empty?
    return @tree.pop if @tree.size == 1

    top = @tree.first
    @tree[0] = @tree.pop
    i = 0
    while i != nil
      i = push_down(i)
    end
    top
  end

  def push(val)
    @tree.push(val)
    i = @tree.count - 1
    while i != nil
      i = pop_up(i)
    end
    self
  end

  def size
    @tree.size
  end

  def empty?
    @tree.empty?
  end

  def to_a
    clone = Heap.new(@tree, &@comp)
    array = []
    while clone.size > 0
      array << clone.pop
    end
    array
  end

  def print_tree
    recursive_print(0, 0)
  end

  private

  def left(i)
    ret = 2 * i + 1
    return nil if ret >= @tree.count
    ret
  end

  def right(i)
    ret = 2 * i + 2
    return nil if ret >= @tree.count
    ret
  end

  def parent(i)
    return nil if i == 0
    (i - 1) / 2
  end

  def comp(a, b)
    @comp.call(a, b)
  end

  def swap(i, j)
    tmp = @tree[i]
    @tree[i] = @tree[j]
    @tree[j] = tmp
  end

  def push_down(i)
    target_i = if left(i) && right(i)
                 comp(@tree[left(i)], @tree[right(i)]) ? left(i) : right(i)
               else
                 left(i)
               end
    if target_i && !comp(@tree[i], @tree[target_i])
      swap(i, target_i)
      return target_i
    else
      return nil
    end
  end

  def pop_up(i)
    if parent(i) && !comp(@tree[parent(i)], @tree[i])
      swap(i, parent(i))
      return parent(i)
    else
      return nil
    end
  end

  def recursive_print(i, level)
    return nil if i.nil?
    recursive_print(right(i), level + 1)
    puts ' ' * level + "- #{@tree[i]}"
    recursive_print(left(i), level + 1)
  end
end
