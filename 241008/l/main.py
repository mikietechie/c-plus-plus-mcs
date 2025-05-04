import struct
import math


def main():
    p, q = map(int, input().split())

    # Calculate using Python's float (64-bit) but we'll handle as 80-bit
    num = p / q

    # Pack as 64-bit double first
    packed = struct.pack("!d", num)

    # Convert to binary and hex strings (64-bit)
    binary = " ".join(f"{b:08b}" for b in packed)
    hexadecimal = " ".join(f"{b:02x}" for b in packed).upper()

    # For 80-bit we would need to extend this, but Python's struct doesn't support 80-bit floats
    print("64-bit binary:", binary)
    print("64-bit hex:", hexadecimal)

    # Alternative approach using ctypes for 80-bit (if available)
    try:
        import ctypes

        class LongDouble(ctypes.Structure):
            _fields_ = [("bytes", ctypes.c_ubyte * 10)]

        ld = LongDouble()
        ld.value = ctypes.c_longdouble(num)

        # Get the 10 bytes of 80-bit representation
        byte_repr = bytes(ld.bytes)

        binary_80 = " ".join(f"{b:08b}" for b in byte_repr)
        hex_80 = " ".join(f"{b:02x}" for b in byte_repr).upper()

        print("80-bit binary:", binary_80)
        print("80-bit hex:", hex_80)
    except Exception as e:
        print("80-bit not supported:", e)


if __name__ == "__main__":
    main()
