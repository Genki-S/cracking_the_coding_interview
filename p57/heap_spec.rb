require 'rspec'
require_relative './heap'

describe Heap do
  let(:data) { [7, 1, 3, 6, 5, 10, 2, 9, 8, 4] }

  before do
    data.each do |datum|
      heap.push(datum)
    end
  end

  context 'when it is initialized with &:<' do
    subject(:heap) { Heap.new(&:<) }

    it 'creates a minimum heap' do
      expect(heap.to_a).to eq(data.sort)
    end
  end

  context 'when it is initialized with &:>' do
    subject(:heap) { Heap.new(&:>) }

    it 'creates a maximum heap' do
      expect(heap.to_a).to eq(data.sort{ |a, b| b <=> a })
    end
  end
end
