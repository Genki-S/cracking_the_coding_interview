class String
  BINARY_CHARS = %w(0 1).freeze
  HEX_CHARS = %w(0 1 2 3 4 5 6 7 8 9 A B C D E F).freeze
  HEX_TO_BINARY = {
    '0' => '0000',
    '1' => '0001',
    '2' => '0010',
    '3' => '0011',
    '4' => '0100',
    '5' => '0101',
    '6' => '0110',
    '7' => '0111',
    '8' => '1000',
    '9' => '1001',
    'A' => '1010',
    'B' => '1011',
    'C' => '1100',
    'D' => '1101',
    'E' => '1110',
    'F' => '1111',
  }.freeze

  def is_binary?
    self.split('').all? { |c| BINARY_CHARS.include?(c) }
  end

  def is_hex?
    self.upcase.split('').all? { |c| HEX_CHARS.include?(c) }
  end

  def binary_to_integer
    val = 0
    self.reverse.split('').each_with_index do |c, i|
      val += 2 ** i if c == '1'
    end
    val
  end

  def hex_to_integer
    self.hex_to_binary.binary_to_integer
  end

  def hex_to_binary
    self.upcase.split('').inject('') do |bin, c|
      bin + HEX_TO_BINARY[c]
    end
  end
end

class CompHexBin
  def initialize(hex:, bin:)
    raise ArgumentError unless hex.is_a?(String) && bin.is_a?(String)
    raise ArgumentError unless hex.is_hex? && bin.is_binary?
    @hex = hex
    @bin = bin
  end

  def equal?
    @hex.hex_to_integer == @bin.binary_to_integer
  end
end
