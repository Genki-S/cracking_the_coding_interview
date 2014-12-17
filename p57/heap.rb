require_relative 'heap/binary_heap'

class Heap
  class UnknownHeapTypeError < StandardError; end

  HEAP_CLASS_BY_TYPE = {
    binary: BinaryHeap,
  }.freeze

  def initialize
    raise RuntimeError, 'Please use `Heap.build` instead.'
  end

  def self.build(data: [], type: :random, &comparator)
    if HEAP_CLASS_BY_TYPE.keys.include?(type)
      HEAP_CLASS_BY_TYPE[type].new(data: data, comparator: comparator)
    else
      # Select random heap to test all heap types with CI
      selected_type = HEAP_CLASS_BY_TYPE.keys.sample
      HEAP_CLASS_BY_TYPE[selected_type].new(data: data, comparator: comparator)
    end
  end
end
