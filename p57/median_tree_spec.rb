require 'rspec'
require_relative './median_tree'

class Array
  def median
    sorted = self.sort
    len = self.length
    (sorted[(len - 1) / 2] + sorted[len / 2]).to_f / 2
  end
end

describe MedianTree do
  let(:sorted) { data.sort }
  subject(:mtree) { MedianTree.new }

  before do
    data.each do |datum|
      mtree.push(datum)
    end
  end

  context 'when there are odd numbers of data' do
    # [*1..100].sample(9).shuffle
    let(:data) { [87, 85, 97, 55, 66, 13, 32, 67, 29] }

    it 'returns median value' do
      expect(mtree.median).to eq(data.median)
    end
  end

  context 'when there are even numbers of data' do
    let(:data) { [87, 85, 97, 55, 66, 13, 32, 67, 29, 39] }

    it 'returns the average of 2 median numbers' do
      expect(mtree.median).to eq(data.median)
    end
  end
end
