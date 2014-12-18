require 'rspec'
require_relative './heap'

describe Heap do
  let(:data) { [*-100..100].sample(sample_size) }
  let(:sample_size) { [*1..100].sample }

  context 'when it is initialized with data' do
    subject(:heap) { Heap.build(data: data, &:<) }

    it 'creates a heap' do
      expect(heap.to_a).to eq(data.sort)
    end
  end

  context 'when data is pushed one by one' do
    before do
      data.each do |datum|
        heap.push(datum)
      end
    end

    context 'when it is initialized with &:<' do
      subject(:heap) { Heap.build(&:<) }

      it 'creates a minimum heap' do
        expect(heap.to_a).to eq(data.sort)
      end
    end

    context 'when it is initialized with &:>' do
      subject(:heap) { Heap.build(&:>) }

      it 'creates a maximum heap' do
        expect(heap.to_a).to eq(data.sort{ |a, b| b <=> a })
      end
    end
  end
end
