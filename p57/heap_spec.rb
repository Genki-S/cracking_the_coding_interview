require 'rspec'
require_relative './heap'

describe Heap do
  let(:data) { [*-100..100].sample(10) }

  context 'when it is initialized with data' do
    subject(:heap) { Heap.build(data: data, &:<) }

    it 'creates a heap' do
      expect(heap.to_a).to eq(data.sort)
    end
  end

  context 'whne data is pushed one by one' do
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
