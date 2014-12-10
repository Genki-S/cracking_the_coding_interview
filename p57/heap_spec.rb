require 'rspec'
require_relative './heap'

describe Heap do
  let(:data) { [*-100..100].sample(10) }

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
