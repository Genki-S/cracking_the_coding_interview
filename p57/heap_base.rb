class HeapBase
  class NotImplementedError < RuntimeError; end

  def initialize(data: [], comparator:)
    raise NotImplementedError
  end

  def top
    raise NotImplementedError
  end

  def pop
    raise NotImplementedError
  end

  def push(val)
    raise NotImplementedError
  end

  def size
    raise NotImplementedError
  end

  def empty?
    raise NotImplementedError
  end

  def to_a
    raise NotImplementedError
  end

  def merge(other)
    raise NotImplementedError
  end
end
