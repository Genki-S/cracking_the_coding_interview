class Heap
  def initialize(&comparator)
    @tree = []
    @comp = comparator
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
    if left(i) && !comp(@tree[i], @tree[left(i)])
      swap(i, left(i))
      return left(i)
    elsif right(i) && !comp(@tree[i], @tree[right(i)])
      swap(i, right(i))
      return right(i)
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

class MedianTree
  def initialize
    @large_heap = Heap.new(&:<)
    @small_heap = Heap.new(&:>)
  end

  def median
    if @large_heap.size > @small_heap.size
      @large_heap.top
    elsif @large_heap.size < @small_heap.size
      @small_heap.top
    else
      (@large_heap.top + @small_heap.top).to_f / 2
    end
  end

  def push(val)
    if @large_heap.empty? || val > @large_heap.top
      @large_heap.push(val)
    else
      @small_heap.push(val)
    end
    balance_tree
    true
  end

  def print_tree
    @large_heap.print_tree
    puts "==="
    @small_heap.print_tree
  end

  private

  def balance_tree
    while @large_heap.size > @small_heap.size
      @small_heap.push(@large_heap.pop)
    end
    while @small_heap.size > @large_heap.size
      @large_heap.push(@small_heap.pop)
    end
  end
end
