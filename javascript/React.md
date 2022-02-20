### Set state
#### if calling only once

```js
method() {
    this.setState({
        count: this.state.count + 1
    }, () => console.log('this is the callback.', this.state.count))
}
 ```

#### if calling multiple times
```js
method() {
    this.setState((prevState, props) => {
        count: prevState.count + 1 +props.countJump
    })
}
```

### Bind event
```js
<button onClick={this.clickHandler.bind(this)} >click</button>
//OR
<button onClick={() => this.clickHandler()} >click</button>
//OR
clickHandler = () => {
    console.log(this)
}
<button onClick={this.clickHandler} >click</button>
//OR Recommended (Binding happens in the constructor so wont happen in each rerender)
constructor(){
    super(props)
    this.clickHandler = this.clickHandler.bind(this)
}
<button onClick={this.clickHandler} >click</button>
```

### Conditional rendering
```js
render(){
    return this.state.booleanValue ? <TrueComponent /> : <FalseComponent />
}
//OR
this.state.booleanValue && <TrueComponent />
```

### Listing
```js
const List = () => {
    const array = [
        {
            id: 1,
            name: "Task one",
            color: "red",
            excerpt: "This is the task one and we..."
        }
        , {
            id: 2,
            name: "Task two",
            color: "#e1e1e1e1",
            excerpt: "This is the task two and we..."
        }]
    return(
        <>
            {
                array.map(object => <ListItem key={object.id.toString()} data={object} />)
            }
        </>
    )
}
//key prop is used by react for identifying diff in code on rerender
//Keys Must Only Be Unique Among Siblings
//if no uid exists, combine 2 fields
array.map((object, index) => <ListItem key={index+object.name} data={object} />)
//OR
<div>
    {React.Children.toArray(array.map(object => <p>{object}</p>))}
</div>
//Lasr resort: If no uid exists in the array, use index of the array as key
array.map((object, index) => <ListItem key={index} data={object} />)
```

### React.Suspense & React.lazy
```js
import React, { Suspense, lazy } from 'react';
// For dynamically loading stuff (to reduce browser load).This component is loaded dynamically
const OtherComponent = React.lazy(() => import('./OtherComponent'));
// ./OtherComponent only imported lazily when in need of <OtherComponent />
function MyComponent() {
  return (
    // Displays <Spinner> until OtherComponent loads
    <React.Suspense fallback={<Spinner />}>
      <div>
        <OtherComponent />
      </div>
    </React.Suspense>
  );
}

//To show error on fail
import React, { Suspense } from 'react';
import MyErrorBoundary from './MyErrorBoundary'; //https://reactjs.org/docs/error-boundaries.html

const OtherComponent = React.lazy(() => import('./OtherComponent'));
const AnotherComponent = React.lazy(() => import('./AnotherComponent'));

const MyComponent = () => (
  <div>
    <MyErrorBoundary>
      <Suspense fallback={<div>Loading...</div>}>
        <section>
          <OtherComponent />
          <AnotherComponent />
        </section>
      </Suspense>
    </MyErrorBoundary>
  </div>
);

//Use with routes (react-router-dom)
//https://reactjs.org/docs/code-splitting.html#route-based-code-splitting
import React, { Suspense, lazy } from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';

const Home = lazy(() => import('./routes/Home'));
const About = lazy(() => import('./routes/About'));

const App = () => (
  <Router>
    <Suspense fallback={<div>Loading...</div>}>
      <Switch>
        <Route exact path="/" component={Home}/>
        <Route path="/about" component={About}/>
      </Switch>
    </Suspense>
  </Router>
);
```

# Blog
### How I created a logout route in a React / Firebase project
```js
import React, {useEffect} from 'react';
import { useAuth } from '../contexts/AuthContext';
import { useNavigate, Navigate } from 'react-router-dom';

export default function Logout(){
    const { currentUser, logout } = useAuth()
    const history = useNavigate()
    async function handleLogout() {
        try {
        await logout()
        history("/login")
        } catch {
        }
    }
    useEffect(() => {
        handleLogout()
    }, [])
    
    if(currentUser==null){
        return(<Navigate to={'/'}></Navigate>)
    }
    else{
        return(<></>)
    }
}
```
How I called it
```js
<Route exact path='/logout' element={<ProtectedRoute/>}>
    <Route exact path='/logout' element={
      <React.Suspense fallback={<>...</>}>
        <Logout />
      </React.Suspense>
    }/>
</Route>
```
Whats in ProtectedRoute?
```js
import React, { useContext } from 'react';
import { useAuth } from '../contexts/AuthContext';
import {Route, Navigate, Outlet} from 'react-router-dom';

export default function ProtectedRoute(props){
    const { currentUser } = useAuth()
    if (currentUser){
        if(currentUser==null){
            return(<Navigate to={props.redirectTo}></Navigate>)
        }
        else{
            return(<Outlet />)
        }
    }
    else{
        return null
    }
}
```
### How to create a protected route in React
```js
import ProtectedRoute from './components/ProtectedRoute';
export default function App() {
  return (
    <Routes>
      <Route exact path='/home' element={<ProtectedRoute/>}>
        <Route exact path='/home' element={
          <React.Suspense fallback={<>...</>}>
            <Dashboard />
          </React.Suspense>
        }/>
      </Route>
    <Routes>
  );
}
```
The ProtectedRoute component;
```js
import React, { useContext } from 'react';
import { useAuth } from '../contexts/AuthContext';
import {Route, Navigate, Outlet} from 'react-router-dom';

export default function ProtectedRoute(props){
    const { currentUser } = useAuth()
    if (currentUser){
        if(currentUser==null){
            return(<Navigate to={props.redirectTo}></Navigate>)
        }
        else{
            return(<Outlet />)
        }
    }
    else{
        return null
    }
}
```
```
```