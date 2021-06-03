import React from 'react'
import { withRouter } from 'react-router-dom'

import {

  Card,
  overrideThemeVariables
} from 'ui-neumorphism'


import { FitnessApp } from '../examples'

const importCode = `import React, { Component } from 'react'

import { Button } from 'ui-neumorphism'
import 'ui-neumorphism/dist/index.css'

class Example extends Component {
  render() {
    return <Button />
  }
}
`
const themeUtilCode = `import React, { Component } from 'react'

import { overrideThemeVariables } from 'ui-neumorphism'
import 'ui-neumorphism/dist/index.css'

class App extends Component {
  componentDidMount() {
    // takes an object of css variable key-value pairs
    overrideThemeVariables({
      '--light-bg': '#E9B7B9',
      '--light-bg-dark-shadow': '#ba9294',
      '--light-bg-light-shadow': '#ffdcde',
      '--dark-bg': '#292E35',
      '--dark-bg-dark-shadow': '#21252a',
      '--dark-bg-light-shadow': '#313740',
      '--primary': '#8672FB',
      '--primary-dark': '#4526f9',
      '--primary-light': '#c7befd'
    })
  }

  ...
}
`

const themes = {
  'light-1': {
    '--light-bg': '#E9B7B9',
    '--light-bg-dark-shadow': '#ba9294',
    '--light-bg-light-shadow': '#ffdcde',
    '--primary': '#ff1744',
    '--primary-dark': '#d50000',
    '--primary-light': '#ff8a80'
  },
  'light-2': {
    '--light-bg': '#B9D7D2',
    '--light-bg-dark-shadow': '#94aca8',
    '--light-bg-light-shadow': '#defffc',
    '--primary': '#009688',
    '--primary-dark': '#00695c',
    '--primary-light': '#80cbc4'
  },
  'light-3': {
    '--light-bg': '#D6DDFB',
    '--light-bg-dark-shadow': '#abb1c9',
    '--light-bg-light-shadow': '#ffffff',
    '--primary': '#9c27b0',
    '--primary-dark': '#6a1b9a',
    '--primary-light': '#ce93d8'
  },
  'light-4': {
    '--light-bg': '#cccccc',
    '--light-bg-dark-shadow': '#a3a3a3',
    '--light-bg-light-shadow': '#f5f5f5',
    '--primary': '#424242',
    '--primary-dark': '#616161',
    '--primary-light': '#9e9e9e'
  },
  'dark-1': {
    '--dark-bg': '#292E35',
    '--dark-bg-dark-shadow': '#21252a',
    '--dark-bg-light-shadow': '#313740'
  },
  'dark-2': {
    '--dark-bg': '#3E3D42',
    '--dark-bg-dark-shadow': '#323135',
    '--dark-bg-light-shadow': '#4a494f'
  },
  'dark-3': {
    '--dark-bg': '#243441',
    '--dark-bg-dark-shadow': '#1d2a34',
    '--dark-bg-light-shadow': '#2b3e4e'
  },
  'dark-4': {
    '--dark-bg': '#515568',
    '--dark-bg-dark-shadow': '#414453',
    '--dark-bg-light-shadow': '#61667d'
  },
  default: {
    '--light-bg': '#E4EBF5',
    '--light-bg-dark-shadow': '#bec8e4',
    '--light-bg-light-shadow': '#ffffff',
    '--dark-bg': '#444444',
    '--dark-bg-dark-shadow': '#363636',
    '--dark-bg-light-shadow': '#525252',
    '--primary': '#2979ff',
    '--primary-dark': '#2962ff',
    '--primary-light': '#82b1ff'
  }
}

class Home extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      theme: 'default'
    }
  }

  handleThemeChange(e) {
    const theme = e.active || 'default'
    this.setState({ theme })
    overrideThemeVariables(themes[theme])
  }

  // handleExampleClick(e) {
  //   this.props.history.push('/examples')
  // }

  render() {
    const { dark } = this.props
    return (
      <Card flat dark={dark} className='py-2'>
        <br />
        <FitnessApp dark={dark} />
        <br />
      </Card>
    )
  }
}

export default withRouter(Home)