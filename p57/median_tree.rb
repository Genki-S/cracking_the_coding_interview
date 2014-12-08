require_relative './heap'

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
