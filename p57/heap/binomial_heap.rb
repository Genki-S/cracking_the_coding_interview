require_relative '../heap_base'

# order: the order of a binomial tree regarding self as the root
class Node
  attr_accessor *%i(
    val
    order
    parent
    children
  )

  def initialize(val)
    @val = val
    @order = 0
    @parent = nil
    @children = []
  end
end

class BinomialHeap < HeapBase
  attr_reader :head_by_order

  def initialize(data: [], comparator:)
    @head_by_order = {}
    @comp = comparator
    data.each do |datum|
      self.push(datum)
    end
  end

  def top
    val = nil
    @head_by_order.each do |order, head|
      val ||= head.val
      val = comp(val, head.val) ? val : head.val
    end
    val
  end

  def pop
    return nil if @head_by_order.empty?
    # TODO: have a pointer to point minimum value node to make this methos O(1)
    target = nil
    @head_by_order.each do |order, head|
      target ||= head
      target = head if comp(head.val, target.val)
    end
    @head_by_order.delete(target.order)
    target.children.each do |child|
      merge_tree(child)
    end
    target.val
  end

  def push(val)
    node = Node.new(val)
    merge_tree(node)
  end

  def size
    count = 0
    @head_by_order.each do |order, head|
      count += 2 ** order
    end
    count
  end

  def empty?
    @head_by_order.empty?
  end

  def to_a
    values = []
    @head_by_order.each do |order, node|
      values += gather_nodes(node).map(&:val)
    end
    new_heap = BinomialHeap.new(data: values, comparator: @comp)
    array = []
    while new_heap.size > 0
      array << new_heap.pop
    end
    array
  end

  def merge(another_heap)
    another_heap.each do |order, head|
      merge_tree(head)
    end
  end

  def print_tree
    raise RuntimeError, 'TODO: make it work'
    @head_by_order.each do |order, head|
      puts "=== order: #{order} ==="
      print_recursive(head, 0)
    end
  end

  private

  def comp(a, b)
    @comp.call(a, b)
  end

  def merge_tree(tree)
    target = self.head_by_order[tree.order]
    unless target
      self.head_by_order[tree.order] = tree
      return
    end

    self.head_by_order.delete(tree.order)
    base, other = comp(target.val, tree.val) ? [target, tree] : [tree, target]
    base.children.unshift(other)
    base.order += 1
    merge_tree(base)
  end

  def gather_nodes(node)
    node.children.inject([node]) do |children, child|
      children += gather_nodes(child)
    end
  end

  def print_recursive(head, depth)
    print "-#{head.val}"
    head.children.reverse.each do |child|
      print_recursive(child, depth + 1)
      puts ''
      print ' ' * depth
    end
  end
end
