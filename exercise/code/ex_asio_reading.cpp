#include <doctest/doctest.h>
#include <boost/asio.hpp>

namespace asio = boost::asio;

TEST_CASE("asio")
{

  /// understand basics of asio
  /**
   * https://think-async.com/Asio/boost_asio_1_30_2/doc/html/boost_asio/overview.html 
   * 
   * overview shows the concepts of asio. it's the beginning of the complete understanding of asio.
   */
  SUBCASE("reading overview part 1")
  {
    /**
     * # rationale
     * 
     * - portability
     * - scalability
     * - efficiency
     * - model concepts from established APIs such as BSD sockets
     * - ease of use : taking a toolkit, rather than framework, approach 
     * - basis for further abstraction
     * 
     * # basic asio anatomy
     * connect operation:
     * - app -> io object (socket) -> io context -> os
     * - and backwards
     *
     * # asynchronous model
     * 
     * ## asynchronous operations 
     * 
     * - intiating function
     * - async operation
     * - completion handler 
     *    - a user provided, move-only function object
     *    - invoked at most once with the result of the async operation
     *   
     * ## asynchronous agents
     * 
     * - an async agent is a sequential composition of async operations.
     * - an async agent is an entity that may perform work concurrently with other agents
     * - async agents are to async operations as threads are to synchronous operations
     * - this is a purely notional construct to visualize the sequence (chain) of async operation and
     *   completion handler.
     * 
     * when using asio to build an app, then there appears async agents like session, 
     * server, and client. for timers, it can be an entity or an actor in the app.
     * 
     * ## associated characteristics and associators
     * 
     * - an allocator, which determines how the agent's async ops obtain memory resources
     * - a cancellation slot, which determines how the agent's async ops support cancellation
     * - an executor, which determines how the agent's completion handler will be queued and run
     * 
     * ### specification of an associator 
     * 
     * Given an associator trait named associated_R, having:
     * - a source value s of type S, in this case the completion handler and its type. 
     * - a set of type requirements (or a concept) R that define the synatatic and semantic
     *   requirements of the associated characteristic, 
     * - a candidate value c of type C that meets the type requirements R, which represents 
     *   a default implementation of the associated characteristic, supplied by the async 
     *   operation. 
     * 
     * the async operation uses the associator trait to compute:
     * - the type associated_R<S, C>::type, and 
     * - the value associated_R<S, C>::get(s, c)
     * that meet the requirements defined in R.
     * 
     * The above description shows the gist of template meta programming or generic programming. 
     * 
     * TODO: need to code concrete examples.
     * 
     * ## child agents
     * 
     * Part of async agent, meaning the subsqeuence of async op and completion handler.
     * 
     * ## executors
     * 
     * An agent's executor determines how the agent's completion handlers are queued and
     * ultimately run.
     * 
     * ...
     * 
     * Thus, an async agent's associated executor represents a policy of how, where, and
     * when the agent should run, specified as a cross-cutting concern to the code that 
     * makes up the agent.
     * 
     * ## allocators
     * 
     * Every async agent has an associated allocaor. An agent's allocator is an interface
     * used by the agent's async operations to obtain per-operation stable memory resources
     * (POSMs). This name reflects the fact that the memory is per-operation because 
     * the memory is only retained for the lifetime of that operation, and stable, because
     * the memory is guranteed to be available at that location throughout the operation.
     * 
     * ## cancellation
     * 
     * In asio, many objects, such as sockets and timers, support object-wide cancellation
     * of outstanding async operations via their close or cancel member funcions. However, 
     * certain async operations also support indivisual, targeted cancellation. This per-
     * operation cancellation is enabled by specifying that every async agent has an
     * associated cancellation slot. 
     * 
     * To support cancellation, an async operation installs a cancellation handler into 
     * the agent's slot. The cancellation handler is a function object that will be 
     * invoked when a cancellation signal is emitted by the user into the slot. 
     * 
     * ## completion tokens
     * 
     * A key goal of asio's async model is to support multiple composition mechanisms. 
     * This is achieved via a completion token, which the user passes to an async op's
     * initiating function to customize the API surface of the library. 
     * 
     * wow! this is a magician's therapy. async_result is a templated type to provide
     * traits to support generic types in async operations.
     * 
     * NOTE: 
     *  - type level abstractions with concepts (type requirements and traits) 
     *  - type inferences with auto, decltype 
     *  - variadic template arguments
     * 
     * ## supporting library elements
     * 
     * asio async model is enabled by the library elements listed:
     * - completion_signature concept
     * - completion_handler_for concept
     * - async_result trait
     * - async_initiate function
     * - completion_token_for concept
     * - associator trait
     * - associated_executor trait 
     * - associated_allocator trait
     * - associated_cancellation_slot trait 
     * 
     * TODO: Looking at concrete examples is crucial.
     * 
     * ## higher level abstractions
     * 
     * ths async support is based on the proactor design pattern. 
     * 
     * ### proactor and asio
     * 
     * - async op
     * - async op processor 
     * - completion event queue
     * - completion handler 
     * - async event demultiplexer 
     * - proactor 
     * - initiator
     * 
     * ### impl. using reactor
     * 
     * - async op processor 
     *    - select, epoll or kqueue.
     * - completion event queue
     *    - a linked list of completion handlers
     * - async event demultiplexer
     *    - this is implemented by waiting on an event or condition variable 
     * 
     * ### impl with IOCP
     *  - async op processor
     *    - operating system
     *  - completion event queue
     *    - operating system
     *  - async event demultiplexer
     *    - dequeue events from OS queue.
     * 
     * ## threads and asio
     * 
     * NOTE: follow the author's level of considerations on the design and impl.
     * 
     */
  }

  SUBCASE("reading overview part 2")
  {
    /**
     * # Core concepts and functionality
     * 
     * ## the proactor design pattern: concurrency without threads
     * 
     * 
     * ## strands: threads without explicit locking
     * 
     * A strand is defined as a strictly sequential invocation of event handlers. use of strands
     * allows execution of code in a multithreaded program without the need for explicit locking.
     * 
     * In the case of composed async operations, such as async_read() or async_read_until(), 
     * if a completion handler goes through a strand, then all intermediate handlers should 
     * go through the same strand. this is needed to ensure thread safe access for any
     * objects that are shared between the caller and the composed operation (in the case of
     * async_read() it's the socket, which the caller can close() to cancel the operation.)
     * 
     * To achieve this, all async ops obtain the handler's associated executor by using the 
     * get_associated_executor function.
     * 
     * The exector may be customized for a particular handler type by specifying a nested type
     * executor_type and member function get_executor():
     * 
     * TODO: concrete example required
     * 
     * ## Buffers
     * 
     * scatter-gather op required multiple buffers. therefore we require an abstraction to 
     * represent a collection of buffers. The approach used in asio is to define a type (actually
     * two types) to represent a single buffer. these can be stored in a container, which may
     * be passed to the scatter-gather ops.
     * 
     * mutable_buffer and const_buffer.
     * 
     * ### streambuf for integration with iostreams
     * 
     * - data() => ConstBuferSequence 
     * - prepare() -> MutableBUfferSeqeunce
     * - commit() transferrs data from the front of the output sequence to the back of the 
     *   input sequence.
     * - data is removed from the front of the input sequence by calling the consume().
     * 
     * TODO: build a simple program to demonstrate the features of streambuf 
     * 
     * ### bytewise traversal of buffer sequence
     * 
     * ### buffer literals
     * 
     * async_write(my_socket, "hello"_buf, my_handler)
     * 
     * ### buffer debugging
     * 
     * visual c++, _GLIBCXX_DEBUG.
     * 
     * ### streams, short reads and short writes
     * 
     * Objects that provide stream-oriented io model one or more of the following type requirements:
     * - SyncReadStream
     * - AsyncReadStream
     * - SyncWriteStream 
     * - AsyncWriteStream
     * 
     *  EOF is an error.
     * 
     * ### reactor-style operations
     * 
     * 
     * ### line-based operations 
     * 
     * async_read_until(socket_, data_, "\r\n", boost::bind(...) 
     * 
     * ### custom memory allocation
     * 
     * TODO: look at custom memory allocation example 
     * 
     * ### per-operation cancellation
     * 
     * - CancellationSlot type requirements
     * 
     * - supported operations:
     *   - timers, sockets, posix descriptors
     *   - windows handles, signal sets, serial ports
     *   - SSL streams
     *   - all asio-provided composed operations such as async_read and async_write
     * 
     * ### handler tracking
     * 
     * BOOST_ASIO_ENABLE_HANDLER_TRACKING 
     * action mark is interesting.
     * 
     * ## composition and completion tokens
     * 
     * interesting, but not settled completely except:
     * - stackless coroutines
     * - stackful coroutines
     * - futures 
     * - c++ 20 coroutines support
     * 
     * when c++ has a strong coroutine support including resumable coroutines, 
     * it can be pursued more.
     */
  }

  SUBCASE("reading remaining contents")
  {
    /**
     * Now it becomes more concrete. It's time to write some code and look inside.
     * 
     * Do it!
     */
  }
}