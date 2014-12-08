require_relative './comp_hex_bin'

describe CompHexBin do
  context 'when non-string arguments are passed' do
    let(:hex) { 0xAA }
    let(:bin) { 0b01 }

    it 'should raise ArgumentError' do
      expect { CompHexBin.new(hex: hex, bin: bin) }.to raise_error ArgumentError
    end
  end

  context 'when non-hex string is passed as hex' do
    let(:hex) { 'G' }
    let(:bin) { '0' }

    it 'should raise ArgumentError' do
      expect { CompHexBin.new(hex: hex, bin: bin) }.to raise_error ArgumentError
    end
  end

  context 'when non-binary string is passed as bin' do
    let(:hex) { 'F' }
    let(:bin) { '2' }

    it 'should raise ArgumentError' do
      expect { CompHexBin.new(hex: hex, bin: bin) }.to raise_error ArgumentError
    end
  end

  context 'when valid string arguments are passed' do
    subject { CompHexBin.new(hex: hex, bin: bin).equal? }

    context 'when both hex and bin are equal as value' do
      let(:hex) { 'F' }
      let(:bin) { '1111' }
      it { should be_truthy }
    end

    context 'when both hex and bin are not equal as value' do
      let(:hex) { 'F' }
      let(:bin) { '1110' }
      it { should be_falsey }
    end
  end
end
