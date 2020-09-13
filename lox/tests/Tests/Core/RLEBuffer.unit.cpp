#include <doctest/doctest.h>

#include <Core.hpp>

TEST_SUITE("Lox::RLEBuffer::Count()") {
  TEST_CASE("returns the number of different added elements") {
    Lox::RLEBuffer<int> buffer;
    buffer.Write(1);
    buffer.Write(2);
    buffer.Write(3);

    CHECK(buffer.Count() == 3);
  }

  TEST_CASE("returns the number of equal added elements") {
    Lox::RLEBuffer<int> buffer{1, 1, 1};

    CHECK(buffer.Count() == 3);
  }

  TEST_CASE("returns absolute number of various elements") {
    Lox::RLEBuffer<int> buffer;
    buffer.Write(1);
    buffer.Write(1);
    buffer.Write(1);
    buffer.Write(2);
    buffer.Write(2);
    buffer.Write(1);

    CHECK(buffer.Count() == 6);
  }
}

TEST_SUITE("Lox::RLEBuffer::Size()") {
  TEST_CASE("returns the memory for a single element in the buffer") {
    Lox::RLEBuffer<int> buffer;
    buffer.Write(1);

    CHECK(buffer.Size() == sizeof(int) * 2);
  }

  TEST_CASE("returns the memory size of the buffer") {
    Lox::RLEBuffer<int> buffer{1, 2, 3};

    CHECK(buffer.Size() == 3 * (sizeof(int) * 2));
  }

  TEST_CASE("returns the memory size of the std::byte buffer") {
    Lox::RLEBuffer<std::byte> buffer;
    buffer.Write(std::byte(1));
    buffer.Write(std::byte(2));
    buffer.Write(std::byte(3));

    // Due to struct padding `int` is the smallest unit
    CHECK(buffer.Size() == 3 * (sizeof(int) * 2));
  }

  TEST_CASE("returns the memory size of a compressed buffer") {
    Lox::RLEBuffer<int> buffer{1, 1, 1, 1};

    // Will contain two elements, `1` as the value and `3` for the repeater
    CHECK(buffer.Size() == (sizeof(int) * 2));
  }

  TEST_CASE("returns the memory size of a compressed buffer with various elements") {
    Lox::RLEBuffer<int> buffer{1, 1, 1, 2, 2, 3, 1, 1};

    CHECK(buffer.Size() == 4 * (sizeof(int) * 2));
  }

  TEST_CASE("is actually smaller than a std::vector") {
    // 5 repeating types * sizeof(int)
    Lox::RLEBuffer<int> buffer{1, 1, 1, 2, 2, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5};
    std::vector<int> vec{1, 1, 1, 2, 2, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5};

    REQUIRE(vec.capacity() == 16);
    CHECK(buffer.Size() < (vec.size() * sizeof(int)));
  }
}

TEST_SUITE("Lox::RLEBuffer::Read()") {
  TEST_CASE("reads value from arbitrary index") {
    Lox::RLEBuffer<int> buffer{1, 2, 2, 2, 3};

    CHECK(buffer.Read(0) == 1);
    CHECK(buffer.Read(1) == 2);
    CHECK(buffer.Read(2) == 2);
    CHECK(buffer.Read(3) == 2);
    CHECK(buffer.Read(4) == 3);
  }
}

TEST_SUITE("Lox::RLEBuffer::Free()") {
  TEST_CASE("frees the stored memory") {
    Lox::RLEBuffer<int> buffer{1, 2, 2, 2, 3};

    CHECK(buffer.Size() == (3 * sizeof(int) * 2));
    buffer.Free();
    CHECK(buffer.Size() == 0);
  }
}
