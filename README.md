<h2> Introduction </h2>

  - A lightweight tool to generate sample data elements from a sample space following a user defined distribution. 

  <p>
    It is often desired to generate some sort of test data. In order to do this, one must define the space of all possible values, 
    as well as a policy for how often each value is chosen. 
  </p>
  
  For example, lets say our sample data space is the following vector of strings :

  ```cpp

    std::vector<std::string> sampleSpace {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

  ```
  
  We can then create the following generator, passing in a mean and standard deviation to use for sampling : 

  ```cpp
  
  double sampleMean {5};
  double sampleSD {1};
  Generator<std::string> g(sampleMean, sampleSD, sampleSpace);

  ```

  Then we can generate samples from our sample space : 

  ```cpp
  
  for (uint32_t i = 0; i < 10; ++i) {
    std::cout << g.sample() << "\n";
  }

  ```
  
  When we view the results of these samples, we will notice that they follow a standard 
  distribution defined by the mean and sd parameters.

  


<h2> Building </h2>

<ol>
 <br>
  <li> Download, Build and Install generator with CMake 
    <ul>
      <li> git clone https://github.com/tonyradtke/generator.git </li>
      <li> cd generator </li>
      <li> mkdir build </li>
      <li> cd build </li>
      <li> cmake .. </li>
      <li> make install </li>
    </ul>
  </li>
  <br>
  <li>  Build and Run the demo to make sure things are working 
    <ul> 
      <li> cd demo </li>
      <li> mkdir build </li>
      <li> cd build </li>
      <li> cmake . </li>
      <li> make </li>
      <li> ./bin/__demo__ </li>
    </ul>
  </li>
  <br>
  <li> Include and Link against generator in your project </li>
    <ul>
      <li> find_library("generator" STATIC lib) </li>
      <li> target_link_libraries(${YOUR_BINARY} PUBLIC "simple-zmq-server") </li>
    </ul> 
  </li>
  <br>
</ol>




